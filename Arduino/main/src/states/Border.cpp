#include "Border.h"

void Border::onTick() {
  timer.tick();
  if (timer.hasElapsed())
    show();
}

void Border::onEnter() {
  timer.stop();
  studentPrimeSet.size = 0;
}

void Border::onPressButtonA() {
  timer.stop();
  stateMachine.setState(grayState, true);
}

void Border::onPressButtonB() {
  timer.stop();
  if (studentPrimeSet.size > 0)
    studentPrimeSet.size--;
  show();
}

void Border::onPressButtonC() {
  timer.stop();
  // Check if maximum island limit is reached
  if (studentPrimeSet.size == (1 << variableSize))
    return display.show("No valid & optimized\nsolution can have\nmore terms than\nthe truth table size"), timer.start();

  // Read student border configuration
  bool studentBorder[sizeBorders];
  demux.readMatrix(mapBorders, sizeBorders, studentBorder);
  char studentTruthTable[16] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};

  // Initialize corner indices
  int topLeftCorner = -1;
  int topRightCorner = -1;
  int bottomLeftCorner = -1;
  int bottomRightCorner = -1;

  // Step 1: Identify the four corners of the border
  for (int i = 0; i < rowSize * columnSize; ++i) {
    int row = i / columnSize;
    int col = i % columnSize;

    bool hasTop = studentBorder[getBorderIndex(row, col, Direction::TOP)];
    bool hasBottom = studentBorder[getBorderIndex(row, col, Direction::BOTTOM)];
    bool hasLeft = studentBorder[getBorderIndex(row, col, Direction::LEFT)];
    bool hasRight = studentBorder[getBorderIndex(row, col, Direction::RIGHT)];

    if (hasTop && hasLeft) {
      if (topLeftCorner > -1)
        return display.show("Error: Invalid\nisland shape"), timer.start();
      topLeftCorner = i;
    }
    if (hasTop && hasRight) {
      if (topRightCorner > -1)
        return display.show("Error: Invalid\nisland shape"), timer.start();
      topRightCorner = i;
    }
    if (hasBottom && hasLeft) {
      if (bottomLeftCorner > -1)
        return display.show("Error: Invalid\nisland shape"), timer.start();
      bottomLeftCorner = i;
    }
    if (hasBottom && hasRight) {
      if (bottomRightCorner > -1)
        return display.show("Error: Invalid\nisland shape"), timer.start();
      bottomRightCorner = i;
    }
  }

  // Step 2: Validate all corners were found
  if (topLeftCorner == -1 || topRightCorner == -1 || bottomLeftCorner == -1 || bottomRightCorner == -1)
    return display.show("Error: Gap at\nthe island's corner"), timer.start();

  // Step 3: Calculate rectangle dimensions
  int startCol = topLeftCorner % columnSize;
  int endCol = topRightCorner % columnSize;
  int startRow = topLeftCorner / columnSize;
  int endRow = bottomLeftCorner / columnSize;

  // Step 4: Ensure width and height are powers of 2
  int width = endCol - startCol + 1;
  int height = endRow - startRow + 1;
  if (!Utils::isPowerOfTwo(width) || !Utils::isPowerOfTwo(height))
    return display.show("Error: Invalid\nisland size\nMust be a power\nof two"), timer.start();

  // Step 5: Verify valid rectangle shape
  if ((topRightCorner / columnSize) != startRow || (bottomRightCorner % columnSize) != endCol || (bottomRightCorner / columnSize) != endRow)
    return display.show("Error: Invalid\nisland shape"), timer.start();

  // Step 6: Check continuous top and bottom borders
  for (int col = startCol; col <= endCol; ++col)
    if (!studentBorder[getBorderIndex(startRow, col, Direction::TOP)] || !studentBorder[getBorderIndex(endRow, col, Direction::BOTTOM)])
      return display.show("Error: Gap at\nthe island's border"), timer.start();

  // Step 7: Check continuous left and right borders
  for (int row = startRow; row <= endRow; ++row)
    if (!studentBorder[getBorderIndex(row, startCol, Direction::LEFT)] || !studentBorder[getBorderIndex(row, endCol, Direction::RIGHT)])
      return display.show("Error: Gap at\nthe island's border"), timer.start();

  // Step 8: Validate selected area and update truth table
  for (int row = startRow; row <= endRow; row++) {
    for (int col = startCol; col <= endCol; col++) {
      int index = row * columnSize + col;
      if (educatorTruthTable[index] == '0')
        return display.show("a false index\nwas found in the\nborder selection"), timer.start();
      studentTruthTable[index] = educatorTruthTable[index];
    }
  }

  // Step 9: Process valid border selection
  QuineMcCluskey quineMcCluskey(studentTruthTable, variableSize);
  strcpy(targetSet, quineMcCluskey.primeSet.terms[0]);
  stateMachine.setState(algebraState, true);
}

void Border::onPressButtonD() {
  timer.stop();
  stateMachine.setState(endState, true);
}

void Border::show() {
  char buffer[200] = "";

  if (studentPrimeSet.size != 0)
    StateUtils::formatPrimeSet(variableSize, &studentPrimeSet, buffer, true);
  else
    sprintf(buffer, "Form islands by\ncircling indices\nusing around buttons\n\nVariables:\n-> %d\n", variableSize);

  display.show(buffer);
}

int Border::getBorderIndex(int row, int col, Direction dir) {
  int offset = row * (4 * 2 + 1) + col;
  if (dir == Direction::TOP)
    return offset;
  if (dir == Direction::BOTTOM)
    return offset + 4 + 1 + 4;
  if (dir == Direction::RIGHT)
    return offset + 4 + 1;
  return offset + 4;
}
