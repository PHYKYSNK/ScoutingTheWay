package com.ph;

import java.util.Scanner;

public class StudentManager {
    private  Scanner sc = new Scanner(System.in);
    //限制最大的人数。
    private int maxNumber = 10;
    //设置现在的人数
    private int nowNumber = 0;
    //创建学生数组存储信息。
    private Student stu[] = new Student[maxNumber];

    private int findIndexById(int id) {
        for(int i=0;i<nowNumber;i++) {
            if(id == stu[i].getId()) {
                return i;
            }
        }
        return -1;
    }
    public void printTip() {
        System.out.println("请输入操作序号：");
        System.out.println("1. 添加学生信息");
        System.out.println("2. 删除学生信息");
        System.out.println("3. 修改学生信息");
        System.out.println("4. 查询学生信息");
        System.out.println("5. 显示所有学生信息");
        System.out.println("6. 退出系统");
    }
    public void addStudent() {
        //判断最大人数
        if(nowNumber >= maxNumber) {
            System.out.println("已满！");
            return ;
        }
        System.out.println("添加学生信息 : ");
        //名字可以重复，靠id来判断是否存在
        System.out.println("请输入学生编号：");
        int id = sc.nextInt();
        int index = findIndexById(id);
        if(index != -1) {
            System.out.println("该编号已存在 ! 无需重复添加");
        }
        else {
            System.out.println("请输入学生姓名：");
            String name = sc.next();
            System.out.println("请输入学生年龄：");
            int age = sc.nextInt();
            System.out.println("请输入学生成绩：");
            double score = sc.nextDouble();
            Student stu1 = new Student(id, name, age, score);
            stu[nowNumber++] = stu1;
            System.out.println("添加成功！");
        }
    }
    public void deleteStudent() {
        System.out.println("删除学生信息 : ");
        System.out.println("请输入学生编号：");
        int id = sc.nextInt();
        int index = findIndexById(id);
        if(index != -1) {
            for(int i=index;i<nowNumber-1;i++) {
                stu[i] = stu[i+1];
            }
            nowNumber--;
            System.out.println("删除成功！");
        }
        else {
            System.out.println("未找到该学生！");
        }
    }
    public void updateStudent() {
        //根据学生id 查询学生信息并修改
        System.out.println("修改学生信息 : ");
        System.out.println("请输入学生编号：");
        int id = sc.nextInt();
        int index = findIndexById(id);
        if(index != -1) {
            System.out.println("请输入修改后的信息：");
            System.out.println("请输入学生姓名：");
            String name = sc.next();
            System.out.println("请输入学生年龄：");
            int age = sc.nextInt();
            System.out.println("请输入学生成绩：");
            double score = sc.nextDouble();
            stu[index].setAge(age);
            stu[index].setName(name);
            stu[index].setScore(score);
            System.out.println("修改成功！");
        }
        else {
            System.out.println("未找到该学生！");
        }
    }
    public void queryStudent() {
        //根据id 查询学生信息
        System.out.println("查询学生信息 : ");
        System.out.println("请输入学生编号：");
        int id = sc.nextInt();
        int index = findIndexById(id);
        if(index != -1) {
            System.out.println(stu[index]);
        }
        else {
            System.out.println("未找到该学生！");
        }
    }
    public void showAllStudent() {
        System.out.println("所有学生信息 : ");
        if(nowNumber == 0) {
            System.out.println("暂无数据！");
        }
        for(int i=0;i<nowNumber;i++) {
            System.out.println(stu[i]);
        }
    }
}
