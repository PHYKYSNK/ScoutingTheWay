package t2;

public class Main {
    public static void main(String[] args) {
        func1();
        func2();
        func3(91);
        func4();
    }
    public static void func1() {
        int sum = 0;
        for (int i = 1; i <= 100; i++) {
            if(i%2==0){
                sum += i;
            }
        }
        System.out.println(sum);
    }
    public static void func2() {
        int sum = 0;
        int i = 1;
        while(true) {
            sum += i;
            if(sum > 100) {
                break;
            }
            i++;
        }
        System.out.println(i);
    }
    public static void func3(double score) {
        switch ((int)score / 10) {
            case 9:
            case 10:
                System.out.println("优秀");
            break;
            case 8:
                System.out.println("良好");
                break;
            case 7:
                System.out.println("一般");
                break;
            case 6:
                System.out.println("及格");
                break;
            default:
                System.out.println("不及格");
                break;
        }
    }
    public static void func4() {
        for (int i = 1; i <= 5; i++) {
            for(int j = 1; j <= i; j++) {
                System.out.print('*');
            }
            System.out.println();
        }
    }
}

