package A1;

import java.io.*;

public class Main {
    public static void main(String[] args) {
        //写入文件。
        try(
                BufferedWriter bw = new BufferedWriter(new FileWriter("note\\src\\A1\\hello.txt",true));
                ) {
            bw.write("Hello Java!");
            bw.newLine();
            bw.write("这是第二行内容。");
            bw.newLine();
        }catch(Exception e) {
            e.printStackTrace();
        }

        try (
                FileReader fr = new FileReader("note\\src\\A1\\hello.txt");
                BufferedReader br = new BufferedReader(fr);
                ) {
            String line;
            while((line = br.readLine()) != null) {
                System.out.println(line);
            }
        }catch(Exception e) {
            e.printStackTrace();
        }

        try(
                FileReader fr = new FileReader("note\\src\\A1\\hello.txt");
                BufferedReader br = new BufferedReader(fr);
                FileWriter fw = new FileWriter("note\\src\\A1\\tar.txt");
                BufferedWriter bw = new BufferedWriter(fw);
                ) {
            String line;
            while((line = br.readLine()) != null) {
                bw.write(line);
                bw.newLine();
            }
        }catch(Exception e) {
            e.printStackTrace();
        }

        try(
                BufferedReader br = new BufferedReader(new FileReader("note\\src\\A1\\hello.txt"));
        ) {
            String line;
            while((line = br.readLine()) != null) {
                System.out.println(line);
            }
        }catch(Exception e) {
            e.printStackTrace();
        }
    }
}
