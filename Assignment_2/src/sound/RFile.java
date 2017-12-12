package sound;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;

import javax.sound.sampled.AudioFileFormat;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;

import javafx.event.ActionEvent;
import javafx.scene.control.Button;
import javafx.scene.media.AudioClip;

public class RFile {
	static AudioClip Clip;
	public static final double F = 8000.0;
	public static String H;
	static int f1;
	
	
	static void ca(String h){
		
		H = h;
		f1 = Integer.parseInt(H);
		
	}
	public static void main(String[] args) throws IOException {
		
		      InputStream is = null;
		      char ch;
		      int flag = 0;
		  	  int f = 0, T = 0, f_2 = 0, f_4 = 0;
		  	  int temp = -1; int c;
		  	  int data = 0;  int i = 0;
		  	  
		      ByteArrayOutputStream baos = new ByteArrayOutputStream();

		      try{
		         
		         is = new FileInputStream("src/sound/test.txt");
		         while((data=is.read())!=-1)
		         {
		        	 
		        	byte[] rec = new byte[8000];
		        	
		            ch = (char)data;
		      //      System.out.print(ch+" ");
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
							f_2 = Func.f_table_2(f);
							f_4 = Func.f_table_4(f);
							rec = Func.sound(f_2,f_4, T);
							baos.write(rec);
						}
						f = 0;
						T = 1;
						i = 0;
					    f_2 = Func.f_table_2(f);
						f_4 = Func.f_table_4(f);
						rec = Func.sound(f_2,f_4, T);
					 
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
						f_2 = Func.f_table_2(f);
						f_4 = Func.f_table_4(f);
						rec = Func.sound(f_2,f_4, T);
					 
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
		 		 
		 		 if(f1!=0){
		 		   data2 [h] = (byte) (data1 [h] * Math.cos(2 * (Math.PI) * (h / F) * f1));
		 		   }
		 		 else 
		 			data2 [h] = data1[h];
		 		  
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
		       
		       AudioSystem.write(ais2, AudioFileFormat.Type.WAVE, new
		     	       File("src/sound/audio.wav")
		     	      );
		     } 
		     catch(Exception e) {
		       e.printStackTrace();
		     }

		    }
		    
	     

	 

   
}

