package t3;


import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        func1();
        func2();
        func3();
    }
    public static void func1() {
        int[] num = new int[10];
        int sum = 0,maxx = 0,minn = 0;
        for(int i=0;i<num.length;i++) {
            num[i] = i + 1;
            sum += num[i];
            maxx = Math.max(maxx, num[i]);
            minn = Math.min(minn, num[i]);
        }
        double avg = (double) sum / num.length;
        System.out.println("和 ： " + sum);
        System.out.println("平均数 ： " + avg);
        System.out.println("最大值 ： " + maxx);
        System.out.println("最小值 ： " + minn);
    }
    public static void func2() {
        int[] num = {5, 2, 8, 1, 9, 3, 7, 4, 6};
        int lenn = num.length;
        //排序函数
        Arrays.sort(num);
        
        // 打印排序后的结果
        for(int i = 0; i < num.length; i++) {
            System.out.print(num[i] + " ");
        }
        System.out.println();

        int idx = Arrays.binarySearch(num, 7);
        System.out.println("7的索引为：" + idx);
    }
    public static void func3() {
        int[][] num = new int[3][3];
        for(int i=1;i<=9;i++) {
            int h = (i - 1) / 3;
            int l = (i - 1) % 3;
            num[h][l] = i;
        }
        int ans = 0;
        for(int i=0;i<num.length;i++) {
            for(int j=0;j<num[i].length;j++) {
                System.out.print(num[i][j] + " ");
                if(i == j) ans += num[i][j];
            }
            System.out.println();
        }
        System.out.println(ans);
    }
}
