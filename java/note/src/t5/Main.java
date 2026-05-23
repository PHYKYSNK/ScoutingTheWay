package t5;

public class Main {
    public static void main(String[] args) {
        Person p1 = new Teacher("Trae",1);
        Person p2 = new Student("Cursor",2);
        p1.work();
        p2.work();

        if(p1 instanceof Teacher) {
            Teacher t = (Teacher) p1;
            t.teach();
        }
        if(p2 instanceof Student) {
            Student s = (Student) p2;
            s.study();
        }
    }
}
