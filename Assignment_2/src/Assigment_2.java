import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Assigment_2 { 
	public static final int A = 1000;
	public static final double F = 8000.0;
	static int x = 0;
	static double[] sound(int pitch, int tT, OutputStream os) throws IOException 
	{
		double T = tT * 0.5;
		double n = T * F;
		double [] sample;
		sample= new double[10000];
		x ++ ;
		for(int i = 0;i < n;i++)
		{
			//double sample;
			 
			double a = A * Math.sin(2 * (Math.PI) * (i / F) * pitch);
			
			int g = (int)a;
			
			os.write(g);
			
		//	sample[i] = A * Math.sin(2 * (Math.PI) * (i / 8000.0) * pitch);
			
		}
		
		 /*os.write(82);
		 os.write(73);
		 os.write(70);
		 os.write(70);
		 os.write(173);
		 os.write(193);
		 os.write(10);
		 os.write(0);
		 os.write(87);
		 os.write(65);
		 os.write(86);
		 os.write(69);
		 os.write(102);
		 os.write(109);
		 os.write(116);
		 os.write(32);
		 os.write(16);
		 os.write(0);
		 os.write(0);
		 os.write(0);
		 os.write(1);
		 os.write(0);
		 os.write(1);
		 os.write(0);
		 os.write(34);
		 os.write(86);
		 os.write(0);
		 os.write(0);
		 os.write(34);
		 os.write(86);
		 os.write(0);
		 os.write(0);
		 os.write(1);
		 os.write(0);
		 os.write(8);
		 os.write(0);
		 os.write(73);
		 os.write(78);
		 os.write(70);
		 os.write(79);
		 os.write(18);
		 os.write(0);
		 os.write(0);
		 os.write(0);
		 os.write(73);
		 os.write(78);
		 os.write(65);
		 os.write(77);
		 os.write(9);
		 os.write(0);
		 os.write(0);
		 os.write(0);
		 os.write(65);
		 os.write(66);
		 os.write(77);
		 os.write(90);
		 os.write(48);
		 os.write(48);
		 os.write(52);
		 os.write(56);
		 os.write(0);
		 os.write(10);
		 os.write(100);
		 os.write(97);
		 os.write(116);
		 os.write(97);
		 os.write(111);
		 os.write(193);
		 os.write(10);
		 os.write(0);
		 os.write(10);
*/
	   return sample; 
		
	}

static int f_table_2(int f) { 
	int pitch;
	pitch = f;
	switch (pitch)
	{
	case 0:
		pitch = 0;
		break;
	case 1:
		pitch = 65;
		break;
	case 2:
		pitch = 73;
		break;
	case 3:
		pitch = 82;
		break;
	case 4:
		pitch = 87;
		break;
	case 5:
		pitch = 98;
		break;
	case 6:
		pitch = 110;
		break;
	case 7:
		pitch = 124;
		break;
	default:
		break;
	}
	return pitch;
}
static int f_table_4(int f) {

	int pitch;
	pitch = f;
	switch (pitch)
	{
	case 0:
		pitch = 0;
		break;
	case 1:
		pitch = 262;
		break;
	case 2:
		pitch = 294;
		break;
	case 3:
		pitch = 330;
		break;
	case 4:
		pitch = 349;
		break;
	case 5:
		pitch = 392;
		break;
	case 6:
		pitch = 440;
		break;
	case 7:
		pitch = 494;
		break;
	default:
		break;
	}
	return pitch;
}
   public static void main(String[] args) throws Exception {
      
      InputStream is = null;
      OutputStream os = new FileOutputStream("src/test.wav");
      int c;
      char ch;
      int flag = 0;
  	  int f = 0, T = 0, f_2 = 0, f_4 = 0;
  	  int temp = -1;
  	  int data = 0;
  	  int i = 0;
  	  double [] music;
  	  music= new double[10000];
      try{
         
         is = new FileInputStream("src/text.txt");
       //  InputStream it = new FileInputStream("src/6.wav");
       
        	
         music= sound(5, 2,os);
         music= sound(4, 1,os);
        	
       

       
      
         while((data=is.read())!=-1)
         {
            
            ch = (char)data;
            if (ch == ' ') {
				i++; continue;
			}
			if (ch == ')') {
				temp = -1; flag = 0; i = 0; continue;
			}
			if (ch == '(') {
				flag = 1;  continue;
			}
			if (ch == '-') {
				if (i != 0 && temp != -1) {
					f = temp;
					temp = -1;
					T = 1;
					f_2 = f_table_2(f);
					f_4 = f_table_4(f);
					//music= sound(f_2, T);
				}
				f = 0;
				T = 1;
				i = 0;
				f_2 = f_table_2(f);
				f_4 = f_table_4(f);
				//sound(f_2, T,os);
			}
			else {
				c = (int)ch - '0';
				
				if (flag == 0) {

					f = temp;
					temp = c;
					T = 1;
				}
				if (flag == 1) {

					f = temp;
					temp = -1;
					T = c;
				}

			}

			if (i != 0 && f != -1) {
				f_2 = f_table_2(f);
				f_4 = f_table_4(f);
				//sound(f_2, T,os);
			}   
		//	System.out.print(ch);
		}
           
         
      
      
      }catch(Exception e){
      
         e.printStackTrace();
      }finally{
         
        
         if(is!=null)
            is.close();
      }
      
   }
   
  




}

