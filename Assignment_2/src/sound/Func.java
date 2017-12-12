package sound;
import java.io.IOException;

public class Func {

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
			double a_2 = A * Math.sin(2 * (Math.PI) * (i / F) * pitch_2);
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




}
