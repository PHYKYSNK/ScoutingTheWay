package A5_UDP;

import java.io.*;
import java.net.*;
import java.util.*;

public class UDPSender {
    public static void main(String[] args) {
        DatagramSocket socket = null;

        Scanner sc = new Scanner(System.in);
        try {
            socket = new DatagramSocket();
            System.out.println("===请输入发送的信息===");
            String msg = sc.nextLine();
            byte[] data = msg.getBytes("UTF-8");
            InetAddress address = InetAddress.getByName("localhost");
            int port = 9999;
            DatagramPacket packet = new DatagramPacket(
                data,
                data.length,
                address,
                9999
            );
            socket.send( packet);
            System.out.println("发送成功 ： " + msg);

            //接收响应
            byte[] buf = new byte[1024*8];
            DatagramPacket dp = new DatagramPacket(buf, buf.length);
            socket.receive(dp);
            String response = new String(
                dp.getData(),
                0,
                dp.getLength(),
                "UTF-8"
            );
            System.out.println("收到来自" + dp.getAddress().getHostAddress() + "的消息：" + response);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if(socket != null) {
                    socket.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
