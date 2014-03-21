package org.example.freeimage;

public class FreeImage {

	static {
		System.loadLibrary("FreeImage");
	}

	public static synchronized native boolean resize(int width, int height,
			 String srcFile, String destFile);
	
	public static synchronized native boolean crop(int x1,int y1, int x2, int y2, String src, String dest);
	

}
