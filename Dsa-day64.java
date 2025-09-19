import java.util.*;
class Spreadsheet {
    private Map<String,Integer> cells;
    public Spreadsheet(int rows) {
        cells=new HashMap<>();
    }
    public void setCell(String cell,int value) {
        cells.put(cell,value);
    }
    public void resetCell(String cell) {
        cells.remove(cell);
    }
    public int getValue(String formula) {
        String[] parts=formula.substring(1).split("\\+");
        return getVal(parts[0])+getVal(parts[1]);
    }
    private int getVal(String s) {
        if(Character.isLetter(s.charAt(0))) {
            return cells.getOrDefault(s,0);
        }
        return Integer.parseInt(s);
    }
}
