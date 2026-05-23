package t8;

public class Main {
    public static void main(String[] args) {
        func1();
        System.out.println(stringReverse("abcde"));
        func2();
        func3();
    }
    public static void func1() {
        String s = "Hello java";
        System.out.println("s的长度为 ： " + s.length());
        System.out.println("全部转为大写 ： " + s.toUpperCase());
        String s1 = s.replace("java","python");
        System.out.println("替换后的字符串为 ： " + s1);
        boolean startWithHello = s.startsWith("Hello");
        System.out.println("是否以Hello开头 ： " + startWithHello);
        int indexJava = s.indexOf("java");
        String re = s.substring(indexJava, indexJava + "java".length());
        System.out.println("截取java的结果 ： " + re);
    }
    public static String stringReverse(String s) {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        String re = sb.toString();
        return re;
    }
    public static void func2() {
        String s = "hello world hello java hello";
        int indexHello = 0,cntL = 0,cntHello = 0;
        while((indexHello = s.indexOf("hello",indexHello)) != -1) {
            cntHello++;
            indexHello += "hello".length();
        }
        System.out.println("hello出现的次数为 ： " + cntHello);
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i)=='l') {
                cntL++;
            }
        }
        System.out.println("L出现的次数为 ： " + cntL);
    }
    public static void func3() {
        String s = "123";
        int si = Integer.parseInt(s) + 100;
        System.out.println( si);

        int i = 100;
        String is = Integer.toString(i) + "是个数字";
        System.out.println(is);
    }
}
