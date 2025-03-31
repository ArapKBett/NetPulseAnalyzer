public class NativeBridge {
    static {
        System.loadLibrary("netpulse_analyzer"); // Load C++ library
    }

    public native int getPacketCount(); // JNI method to call C++
}
