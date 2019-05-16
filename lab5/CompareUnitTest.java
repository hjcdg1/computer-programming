import java.util.Scanner;
import java.util.ArrayList;

class Unit
{
    protected String operator;
    protected int left;
    protected int right;

    public Unit(int left, int right)
    {
        this.left = left;
        this.right = right;
    }

    protected void calculate()
    {
    }
}

class CompareUnit extends Unit
{
    protected String result;

    public CompareUnit(int left, int right, String operator)
    {
        super(left, right);
        this.operator = operator;
        calculate();
    }

    protected void calculate()
    {
        if(operator.equals("=="))
            result = (left==right) ? "true" : "false";
        else if(operator.equals("!="))
            result = (left!=right) ? "true" : "false";
        else if(operator.equals("<="))
            result = (left<=right) ? "true" : "false";
        else if(operator.equals("<"))
            result = (left<right) ? "true" : "false";
        else if(operator.equals(">"))
            result = (left>right) ? "true" : "false";
        else if(operator.equals(">="))
            result = (left>=right) ? "true" : "false";
    }

    public String toString()
    {
        if(operator.equals("=="))
            return left+"=="+right+" : "+result;
        else if(operator.equals("!="))
            return left+"!="+right+" : "+result;
        else if(operator.equals("<="))
            return left+"<="+right+" : "+result;
        else if(operator.equals("<"))
            return left+"<"+right+" : "+result;
        else if(operator.equals(">"))
            return left+">"+right+" : "+result;
        else if(operator.equals(">="))
            return left+">="+right+" : "+result;
        else
            return "Nothing!";
    }
}

class MainClass
{
    public static void main(String[] args)
    {
        int a, b;
        String op;
        
        ArrayList<Unit> arr = new ArrayList<Unit>();
        Scanner scan = new Scanner(System.in);
        String[] templine;
        String input_line;
        CompareUnit temp;

        while(true){
            input_line = scan.nextLine();
            if(input_line.equals("QUIT"))
                break;
            else if(input_line.equals("list")){
                for(int j=0; j<arr.size(); j++){
                    System.out.println(arr.get(j));
                }
                continue;
            }
            templine = input_line.split(" ");
            a = Integer.parseInt(templine[0]);
            b = Integer.parseInt(templine[1]);
            op = templine[2];
            temp = new CompareUnit(a, b, op);
            arr.add(temp);
            System.out.println(temp);
        }
    }
}
