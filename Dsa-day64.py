class Spreadsheet:
    def __init__(self, rows: int):
        self.cells = {}

    def setCell(self, cell: str, value: int) -> None:
        self.cells[cell] = value

    def resetCell(self, cell: str) -> None:
        if cell in self.cells:
            del self.cells[cell]

    def getValue(self, formula: str) -> int:
        def get_val(x):
            if x[0].isalpha():
                return self.cells.get(x, 0)
            return int(x)
        parts = formula[1:].split('+')
        return get_val(parts[0]) + get_val(parts[1])
