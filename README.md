FreeImage_Android
=================
Usage:

    import org.example.freeimage.FreeImage;

    class Clazz{
        String origPath, destPath;
        int width, height;
        int left , top , right , bottom;
    
        boolean resize(){
            return FreeImage.resize(width, height, origPath, destPath);
        }
    
        boolean crop(){
            FreeImage.crop(left, top, right, bottom, origPath, destPath);
        }

    }    
    
    
