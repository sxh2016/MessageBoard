// sunxiaohua
// Compile with: javac MsgClient
// Run with:     java MsgClient "54.165.143.235" "sunxiaohua" "my name is sunxiaohua"

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.io.BufferedReader;
import java.net.ServerSocket;
import java.net.InetAddress;
import java.io.InputStreamReader;


public class MsgClient {
    public static void main(String[] args) {
        //String host = "54.164.190.110";
        if(args.length != 3){
           System.out.println("Illegal input, please input like <ip> <name> <message>!");
        }
        int portnum = 5555;
        String[] input = new String[3];
        input[0] = args[0];
        input[1] = args[1];
        input[2] = args[2];
        
        String host = input[0];
        String name = input[1];
        String message = input[2];
         try {
            //int port = Integer.parseInt(args[1]);
        
            Socket socket = new Socket(host, portnum);
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
            output.println(args[1] + "\n" + args[2]);
            socket.close();
        } catch(UnknownHostException e){
        	System.err.println("please input valid address:" + e.getMessage());
        }catch(IOException e){
        	System.err.println(e.getMessage());
        }catch(NumberFormatException e){
        	System.err.println("please input integer for port");
        }catch(IllegalArgumentException e) {
            System.err.println("port out of range:" + e.getMessage());
        }catch(ArrayIndexOutOfBoundsException e) {
            System.err.println("missing argument");
        }
    }
}

