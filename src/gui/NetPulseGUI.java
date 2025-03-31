import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.data.time.Millisecond;
import org.jfree.data.time.TimeSeries;
import org.jfree.data.time.TimeSeriesCollection;

import javax.swing.*;

public class NetPulseGUI {
    private TimeSeries throughputSeries;
    private TrafficSimulator simulator;

    public NetPulseGUI() {
        throughputSeries = new TimeSeries("Throughput (bps)");
        TimeSeriesCollection dataset = new TimeSeriesCollection(throughputSeries);
        JFreeChart chart = ChartFactory.createTimeSeriesChart(
            "Network Throughput", "Time", "Throughput (bps)", dataset);
        JFrame frame = new JFrame("NetPulse Analyzer");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(new ChartPanel(chart));
        frame.pack();
        frame.setVisible(true);

        simulator = new TrafficSimulator(this);
    }

    public void updateThroughput(double bps) {
        throughputSeries.addOrUpdate(new Millisecond(), bps);
    }

    public static void main(String[] args) throws Exception {
        NetPulseGUI gui = new NetPulseGUI();
        gui.simulator.startSimulation();
    }
}
