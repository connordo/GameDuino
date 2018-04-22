import java.io.*;
import java.util.*;
import java.lang.*;


public class spriteconverter{
	public static void main(String[] args){
		if (args.length>1)
		return;
		System.out.println("Converting the file..\n\n\n\n");
		try{
			File imagefilepath = new File(args[0]);
			Scanner scanner = new Scanner(imagefilepath);
			while(scanner.hasNext()){
				scanner.next();
			}
		}
		catch(IOException ex){System.err.println(ex);}
	}
}
