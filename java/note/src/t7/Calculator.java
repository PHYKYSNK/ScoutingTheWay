package t7;


public class Calculator {
    public double divide(int a,int b) {
        if(b == 0) {
            throw new ArithmeticException("除数不能为零");
        }
        return a / b;
    }

}
