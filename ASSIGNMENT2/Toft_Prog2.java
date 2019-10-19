/* ------------------- **
** Shannon Toft        **
** Net id: hg9773      **
** Toft_Prog2.java      **
** ------------------- */

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;
import java.nio.*;
import java.nio.channels.FileChannel;

public class ProducerConsumer
{
    public static void main(String[] args) throws IOException
    {
      String delimiter = " ";
      String[] arguments;
      String read = null;
      int m;
      int n;
      String inFile;
      String outFile;

      //begin prompt
      System.out.println("Enter: <copyfile> <inputfilename> <outputfilename> <numberOfBytes> <bufferSize>\n");
      System.out.print(">> ");

      BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
      try
      {
        read = userIn.readLine();
      }catch(IOException exception)
      {
        exception.printStackTrace();
      }

      arguments = read.split(delimiter);
      //confirm format of arguments
      if(arguments.length != 5)
      {
        System.err.println("Please re-enter in the following form: <copyfile> <inputfilename> <outputfilename> <numberOfBytes> <bufferSize>\n");
        System.exit(1);
      }
      //assign variables and create files
      inFile = arguments[1];
      inFile = inFile + ".txt";
      outFile = arguments[2];
      outFile = outFile + ".txt";
      n = Integer.parseInt(arguments[4]);
      m = Integer.parseInt(arguments[3]);
      //create byte arrays
      byte[] producer = new byte[1024];
      byte[] consumer = new byte[1024];
      byte[] circular = new byte[m];

      FileInputStream fin = new FileInputStream(inFile);
      FileOutputStream fout = new FileOutputStream(outFile);

      int offset = 0;

      while(!fin.equals(fout))
      {
        //random generator
        int start = 1;
        Random rand = new Random();
        start += rand.nextInt(n);
        //check space in buffer
        if(start <= m)
        {
          FileInputStream finStream = new FileInputStream(inFile);
          FileChannel fchannel = finStream.getChannel();
          ByteBuffer bytebuff = ByteBuffer.wrap(circular);
          fchannel.read(bytebuff);
        }
        else
        {
          System.out.println("not enough empty elements.");
        }
        //check space
        if(start <= fin.available())
        {
          for(int i = offset; i < (start + i); i++)
          {
            consumer[i] = circular[i];
          }
          offset += start;
        }
      }
      System.exit(0);
    }
}
