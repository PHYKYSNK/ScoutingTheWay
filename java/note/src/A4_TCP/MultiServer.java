package A4_TCP;

import java.net.*;
import java.io.*;

public class MultiServer {
    public static void main(String[] args) {
        ServerSocket ss = null;

        try {
            ss = new ServerSocket(9999);
            System.out.println("===服务器已启动===");
            while(true) {
                Socket s = ss.accept();
                System.out.println("客户端连接 ：" + s.getPort());
                new Thread(new clientThread(s)).start();
            }
        } catch(Exception e) {
            e.printStackTrace();
        } finally {

        }
    }
    public static class clientThread implements Runnable{
        private Socket s;
        public clientThread(Socket s) {
            this.s = s;
        }
        public void run() {

            try (
                    InputStream is = s.getInputStream();
                    InputStreamReader isr = new InputStreamReader(is);
                    BufferedReader br = new BufferedReader(isr);

                    OutputStream os = s.getOutputStream();
                    OutputStreamWriter osw = new OutputStreamWriter(os);
                    PrintWriter pw = new PrintWriter(osw,true);//true的意义。
                    ){
                String msg = null;
                //System.out.println("===服务器接收消息 ： ");
                while((msg = br.readLine()) != null) {
                    if(msg.equals("exit")) {
                        System.out.println("客户端" + s.getInetAddress() + "已退出===");
                        break;
                    }
                    pw.println("===服务器收到" + s.getPort() + "消息===");
                    System.out.println("===服务器收到" + s.getPort() + "消息===" + msg);
                }
            }catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
