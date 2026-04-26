package com.ph;

import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StudentManager sm = new StudentManager();
        while(true) {
            sm.printTip();
            int choice = sc.nextInt();

            switch(choice) {
                case 1 : sm.addStudent();break;
                case 2 : sm.deleteStudent();break;
                case 3 : sm.updateStudent();break;
                case 4 : sm.queryStudent();break;
                case 5 : sm.showAllStudent();break;
                case 6 : System.out.println("退出系统");return ;
                default : System.out.println("输入错误，请重新输入！");
            }
        }
    }
}
