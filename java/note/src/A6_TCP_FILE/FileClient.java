package A6_TCP_FILE;

import java.io.*;
import java.net.*;

public class FileClient {
    public static void main(String[] args) {
        try (
             Socket s = new Socket("localhost",9999);
             OutputStream os = s.getOutputStream();
             BufferedOutputStream bos = new BufferedOutputStream( os);
             FileInputStream fis = new FileInputStream("note\\src\\A6_TCP_FILE\\lover.txt");
        ){
            System.out.println("===客户端启动===");
            byte[] bf = new byte[1024*8];
            int len;
            while((len = fis.read(bf)) != -1) {
                bos.write(bf,0,len);
            }
            bos.flush();
            System.out.println("文件发送完毕");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
