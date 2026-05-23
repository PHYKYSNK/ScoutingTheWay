package A5_UDP;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UDPReceiver {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        try {
            socket = new DatagramSocket(9999);
            System.out.println("===UDP接收端启动(端口号" + socket.getLocalPort()+ ")===");

            byte[] buf = new byte[1024*8];
            DatagramPacket dp = new DatagramPacket(buf, buf.length);

            socket.receive(dp);
            String msg = new String(
                    dp.getData(),
                    0,
                    dp.getLength(),
                    "UTF-8"
            );
            System.out.println("收到来自" + dp.getAddress().getHostAddress() + "的消息：" + msg);
            String response = "收到";
            byte[] buf2 = response.getBytes("UTF-8");
            DatagramPacket dp2 = new DatagramPacket(
                    buf2,
                    buf2.length,
                    dp.getAddress(),
                    dp.getPort()
            );//两处的变量为什么填得不一样
            socket.send(dp2);
            System.out.println("已发送");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if(socket != null) {
                socket.close();
            }
        }
    }
}
