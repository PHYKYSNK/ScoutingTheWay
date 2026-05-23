package A3;

import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        Socket s = null;
        PrintWriter pw = null;
        OutputStream os = null;
        OutputStreamWriter ow = null;

        BufferedReader br = null;
        try {
            System.out.println("===客户端启动===");
            s = new Socket("localhost",9999);
            System.out.println("===服务器已连接===");
            os = s.getOutputStream();
            ow  = new OutputStreamWriter(os);
            //br = new BufferedReader(ow);
            //socket管道只能传字节。
            pw = new PrintWriter(os,true);
            pw.println("hello,server");
            pw.println("bye,server");
            pw.println("bye,server");
            pw.println("bye,server");
            pw.println("bye,server");
            pw.println("exit");
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            String response = br.readLine();
            System.out.println("===服务器回应：" + response + "===");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {

        }
    }
}
