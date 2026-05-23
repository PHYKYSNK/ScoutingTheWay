package A6_TCP_FILE;

import java.io.*;
import java.net.*;

public class FileServer {
    public static void main(String[] args) {
        System.out.println("===文件服务器启动===");
        try (
            ServerSocket ss = new ServerSocket(9999);
            Socket s = ss.accept();
            FileOutputStream fos = new FileOutputStream("note\\src\\A6_TCP_FILE\\tar.txt");

            InputStream is = s.getInputStream();
            BufferedInputStream bis = new BufferedInputStream(is);
        ){
            System.out.println("===服务器已启动===");
            System.out.println("客户端连接 ：" + s.getPort() + "准备接收文件");
            byte[] buf = new byte[1024*8];
            int len;
            while((len = bis.read(buf)) != -1) {
                fos.write(buf,0,len);
            }
            System.out.println("文件接收完毕");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
