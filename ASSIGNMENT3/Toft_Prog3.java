/* ------------------- **
** Shannon Toft        **
** Net id: hg9773      **
** Toft_Prog3.java     **
** ------------------- */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class TeacherStudent
{
    public static void main(String[] args) throws InterruptedException, IOException
    {
        //declare variables
        int num = 1;
        int start;
        int add;
        String sString;
        String aString;
        //array of students
        ArrayList<Integer> students = new ArrayList<>();

        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        //prompt user
        System.out.println("How many students are at office hours? ");
        sString = stdin.readLine();
        start = Integer.parseInt(sString);
        //fill array of students
        for(int i = 0; i < start; i++)
        {
          students.add(num);
          num++;
        }
        //begin question/answer
        while(students.size() > 0)
        {
          QuestionStart(students.get(0));
          students.remove(0);
          System.out.println();

          System.out.print("How many more students showed up for office hours? ");
          aString = stdin.readLine();
          add = Integer.parseInt(aString);

          while(add > 0)
          {
            students.add(num);
            num++;
            add--;
          }
          Collections.sort(students);
        }

        if(students.size() < 1)
        {
          System.out.println("There are no more students at office hours.");
        }
    }

    //Procedures
    public static void AnswerStart(int s)
    {
      System.out.printf("Answering student %d's question.\n", s);
      AnswerDone(s);
    }

    public static void AnswerDone(int s)
    {
      System.out.printf("Finished answering student %d's question.\n", s);
    }

    public static void QuestionStart(int s)
    {
      System.out.printf("Student %d is asking question.\n", s);
      QuestionDone(s);
    }

    public static void QuestionDone(int s)
    {
      System.out.printf("Student %d is finished asking question.\n", s);
      AnswerStart(s);
    }
}
