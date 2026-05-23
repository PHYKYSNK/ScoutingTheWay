package A3;

import java.net.*;
import java.io.*;
public class SimpleServer {
    public static void main(String[] args) {
        ServerSocket ss = null;
        Socket s = null;
        InputStream is = null;
        BufferedReader br = null;
        InputStreamReader isr = null;
        try {
            ss = new ServerSocket(9999);
            System.out.println("===服务器启动===");
            s = ss.accept();
            System.out.println("===服务器已连接===");

            is = s.getInputStream();
            isr =  new InputStreamReader(is);
            br = new BufferedReader(isr);

            String msg = null;
            System.out.println("===服务器已接收消息 ： ===");
            while((msg = br.readLine()) != null) {
                if(msg.equals("exit")) {
                    break;
                }
                System.out.println(msg);
            }
            System.out.println("===服务器已接收完毕===");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            System.out.println("===服务器已关闭===");
            try {
                ss.close();
                s.close();
                is.close();
                isr.close();
                br.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
