import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class TrafficSimulator {
    private NetPulseGUI gui;

    public TrafficSimulator(NetPulseGUI gui) {
        this.gui = gui;
    }

    public void startSimulation() throws Exception {
        DatagramSocket socket = new DatagramSocket();
        byte[] data = "Simulated UDP Packet".getBytes();
        DatagramPacket packet = new DatagramPacket(data, data.length,
            InetAddress.getByName("localhost"), 12345);
        for (int i = 0; i < 1000; i++) {
            socket.send(packet);
            gui.updateThroughput(data.length * 8 * 100); // Bits per second (100 packets/sec)
            Thread.sleep(10); // 100 packets/sec
        }
        socket.close();
    }
}
