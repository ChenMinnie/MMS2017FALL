import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

import javax.sound.sampled.AudioFileFormat;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;

public class Assignment_2 { 
	
	
	public static final int A = 100;
	public static final double F = 8000.0;
	
	
	
	
	static byte[] sound(int pitch_2,int pitch_4, int tT) throws IOException 
	{   
		
		double n ;
	  
		byte[] data = new byte[(int) (F*tT)];
		
		double T = tT *0.5;
		n = T * F;
		for(int i = 0;i < n;i++)
		{			 
			double a_2 = (A*2) * Math.sin(2 * (Math.PI) * (i / F) * pitch_2);
			double a_4=  A * Math.sin(2 * (Math.PI) * (i / F) * pitch_4);
			data[i] = (byte) a_2;
			data[i*2] += (byte) a_4;
		}
		return data;
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
      char ch;
      int flag = 0;
  	  int f = 0, T = 0, f_2 = 0, f_4 = 0;
  	  int temp = -1; int c;
  	  int data = 0;  int i = 0;
  	  
      ByteArrayOutputStream baos = new ByteArrayOutputStream();

      try{
         
         is = new FileInputStream("src/text.txt");
         while((data=is.read())!=-1)
         {
        	byte[] rec = new byte[8000];
        	
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
					rec =sound(f_2,f_4, T);
					baos.write(rec);
				}
				f = 0;
				T = 1;
				i = 0;
				f_2 = f_table_2(f);
				f_4 = f_table_4(f);
				rec =sound(f_2,f_4, T);
			 
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
			int m = 0;
			if (i != 0 && f != -1) {
				f_2 = f_table_2(f);
				f_4 = f_table_4(f);
				rec =sound(f_2,f_4, T);
			 
			}   
				
			baos.write(rec);
	
		}
           
         
      
      }catch(Exception e){
      
         e.printStackTrace();
      }finally{
         
        
         if(is!=null)
            is.close();
      
      }
     
    
      byte data1 [] = baos.toByteArray();
      byte data2 [] = baos.toByteArray();
 
    
	 for(int h = 0;h < data1.length;h++)
		{			 
		 
		   data2 [h] = (byte) (data1 [h] * Math.cos(2 * (Math.PI) * (h / F) * 100));
		}
  
	 
  	AudioFormat ft = new AudioFormat(40000, 8, 1, true, true);
  	AudioFormat ft2 = new AudioFormat(40000, 8, 1, true, true);
    AudioInputStream ais = new AudioInputStream(
      new ByteArrayInputStream(data1), ft, 
      data1.length / ft.getFrameSize()
    );
    AudioInputStream ais2 = new AudioInputStream(
    	      new ByteArrayInputStream(data2), ft2, 
    	      data2.length / ft.getFrameSize()
    	    );
    try {
      AudioSystem.write(ais, AudioFileFormat.Type.WAVE, new
        File("src/audio_origin.wav")
      );
      AudioSystem.write(ais2, AudioFileFormat.Type.WAVE, new
    	        File("src/audio_f100.wav")
    	      );
    } 
    catch(Exception e) {
      e.printStackTrace();
    }

   }
   

}

