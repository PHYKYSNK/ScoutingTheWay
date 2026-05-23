package A4_TCP;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class MultiClient {
    public static void main(String[] args) {
        Socket s = null;
        try {
            s = new Socket("localhost",9999);
            InputStream is = s.getInputStream();
            InputStreamReader isr = new InputStreamReader( is);
            BufferedReader br = new BufferedReader(isr);

            OutputStream os = s.getOutputStream();
            OutputStreamWriter osw = new OutputStreamWriter(os);
            PrintWriter pw = new PrintWriter(osw,true);

            Scanner sc = new Scanner(System.in);
            //接收消息(启动新线程）
            Thread receive = new Thread(
                    ()->{
                        try {
                            String response;
                            while((response = br.readLine()) != null) {
                                System.out.println("服务器回应 ： " + response);
                            }
                        } catch (Exception e) {
                            System.out.println("连接已断开");
                        }
                    }
            );
            receive.start();
            //发送消息
            String msg;
            //标明自己身份且提示客户输入信息
            System.out.println("===用户" + s.getLocalPort() + "请输入消息(exit退出) : ");
            while((msg = sc.nextLine()) != null) {
                if(msg.equals("exit")) {
                    System.out.println("已退出===");
                    //关闭接收进程
                    pw.println(s.getLocalPort() + "已离线！");
                    //receive.interrupt();
                    break;
                }
                pw.println(msg);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if(s != null) {
                    s.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
