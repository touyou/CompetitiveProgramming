import java.awt.image.BufferedImage;
import java.awt.image.Raster;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import javax.imageio.ImageIO;

public class CraterDetectionTester {
	class ImageData {
		String name;
		int W, H;
		int[] data;
	}
	

	class Rectangle {
		String imageName;
		int xl, xr, yt, yb;

		public Rectangle(String imageName, int xl, int yt, int xr, int yb) {
			this.imageName = imageName;
			this.xl = xl;
			this.xr = xr;
			this.yt = yt;
			this.yb = yb;
		}
	}
	
	boolean overlap(Rectangle a, Rectangle b) {
		int areaA = (a.xr - a.xl + 1) * (a.yb - a.yt + 1);
		int areaB = (b.xr - b.xl + 1) * (b.yb - b.yt + 1);

		int intrXL = Math.max(a.xl, b.xl);
		int intrXR = Math.min(a.xr, b.xr);
		int intrYT = Math.max(a.yt, b.yt);
		int intrYB = Math.min(a.yb, b.yb);

		int intrArea = (intrXL <= intrXR && intrYT <= intrYB ? (intrXR - intrXL + 1) * (intrYB - intrYT + 1) : 0);
		int unionArea = areaA + areaB - intrArea;

		return 10 * intrArea > 3 * unionArea;
	}
	
	void printMessage(String msg) {
		if (debugInfo) {
			System.out.println(msg);
		}
	}

	List<String> readData(String fileName) throws Exception {
		List<String> res = new ArrayList<String>();
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		while (true) {
			String s = br.readLine();
			if (s == null) {
				break;
			}
			res.add(s);
		}
		br.close();
		return res;
	}
	
	ImageData readImage(String imagePath) throws Exception {
		ImageData res = new ImageData();
		res.name = new File(imagePath).getName();
		
    	FileInputStream fis = new FileInputStream(imagePath);
    	byte[] contents = new byte[fis.available()];
    	fis.read(contents);
    	fis.close();
    	
		if (res.name.endsWith(".tif")) {
			// in order not to use JAI for tif images,
			// we rely on special structure of tif files
			// in the training set

			res.W = 1432;
			res.H = 1432;
			res.data = new int[res.W * res.H];
			int pos = 8;
			for (int y = 0; y < 1432; y++)
				for (int x = 0; x < 1432; x++)
					res.data[res.H * x + y] = contents[pos++];

		} else {
			// trying to use ImageIO

			BufferedImage image = null;

			image = ImageIO.read(new ByteArrayInputStream(contents));

			res.W = image.getWidth();
			res.H = image.getHeight();

			res.data = new int[res.W * res.H];
			int pos = 0;

			Raster raster = image.getData();

			for (int x=0; x < res.W; x++)
				for (int y=0; y < res.H; y++) {
					byte[] pix = new byte[3];
					raster.getDataElements(x, y, pix);

					res.data[pos++] = (pix[0] >= 0 ? pix[0] : (int)pix[0] + 256);
				}
		}
		
		return res;
	}

	List<String> imagePaths, gtfPaths;
	List<String> imageNames;
	List<Integer> imageW, imageH;

	String[] runTest() {
		printMessage("Parsing image path and ground truth path files.");
				
		try {
			imagePaths = readData(pathToImagesFile);
		}
		catch (Exception e) {
			System.err.println("ERROR: unable to read data from the image path file.");
			e.printStackTrace();
			return null;
		}
		
		try {
			gtfPaths = readData(pathToGTFile);
		}
		catch (Exception e) {
			System.err.println("ERROR: unable to read data from the ground truth path file.");
			e.printStackTrace();
			return null;
		}
		
		printMessage("Calling init.");
		
		try {
			Integer.parseInt(reader.readLine());
		}
		catch (Exception e) {
			System.err.println("ERROR: unable to parse return from init.");
			e.printStackTrace();
			return null;
		}
		
		imageNames = new ArrayList<String>();
		imageW = new ArrayList<Integer>();
		imageH = new ArrayList<Integer>();
		for (String imagePath : imagePaths) {
			printMessage("Calling processImage for " + imagePath + ".");
			
			ImageData imageData = null;
			
			try {
				imageData = readImage(imagePath);
			}
			catch (Exception e) {
				System.err.println("ERROR: unable to read image data from " + imagePath);
				System.err.println("Please make sure that this file exists and corresponds to an image " +
						"from the training set.");
				e.printStackTrace();
				return null;
			}
			
			imageNames.add(imageData.name);
			imageW.add(imageData.W);
			imageH.add(imageData.H);
			
			writer.println(1);
			writer.println(imageData.name);
			writer.println(imageData.W);
			writer.println(imageData.H);
			writer.println(imageData.data.length);
			for (int elm : imageData.data) {
				writer.println(elm);
			}
			writer.flush();
			
			try {
				Integer.parseInt(reader.readLine());
			}
			catch (Exception e) {
				System.err.println("ERROR: unable to parse return from processImage call.");
				e.printStackTrace();
				return null;
			}
		}
		
		printMessage("Calling getCraters.");
		
		writer.println(2);
		writer.flush();
		
		String[] res = null;
		try {
			int len = Integer.parseInt(reader.readLine());
			res = new String[len];
			for (int i=0; i < len; i++) {
				res[i] = reader.readLine();
			}
		}
		catch (Exception e) {
			System.err.println("ERROR: unable to parse return from getCraters.");
			e.printStackTrace();
			return null;
		}
		
		printMessage("Your solution returned " + res.length + " craters.");
		
		return res;
	}
	
	Process solution;
	BufferedReader reader;
	PrintWriter writer;
	
	int parse(String s, int from, int to) {
		int res = -1;
		try {
			res = Integer.parseInt(s);
		}
		catch (Exception e) {
			return -1;
		}
		if (res < from || res > to || !s.equals("" + res))
			return -1;
		return res;
	}
	
	public CraterDetectionTester() {		
		try {
			solution = Runtime.getRuntime().exec(solutionCmd);
		}
		catch (Exception e) {
			System.err.println("ERROR: unable to execute your solution");
			e.printStackTrace();
			System.exit(0);
		}
		
		reader = new BufferedReader(new InputStreamReader(solution.getInputStream()));
		writer = new PrintWriter(solution.getOutputStream());
        new ErrorStreamRedirector(solution.getErrorStream()).start();
		
        String[] craters = runTest();
		
		solution.destroy();
		
		if (craters == null) {
			return;
		}
		
		printMessage("Reading ground truth data.");
		
		List<String> gtf = new ArrayList<String>();
		
		for (String path : gtfPaths) {
			try {
				gtf.addAll(readData(path));
			}
			catch (Exception e) {
				System.err.println("ERROR: unable to read data from " + path + ".");
				e.printStackTrace();
				System.exit(0);
			}
		}
		
		printMessage("Parsing ground truth data.");
		
		List<Rectangle> modelRect = new ArrayList<Rectangle>();

		boolean[] was = new boolean[imageNames.size()];
		try {
			for (String elm : gtf) {
				boolean find = false;
				for (int i = 0; i < imageNames.size(); i++)
					if (elm.startsWith(imageNames.get(i))) {
						find = true;
						was[i] = true;
						break;
					}
	
				if (!find) continue;
	
				String[] data = elm.split(" : ");
				String imageName = data[0].trim();
	
				int N = Integer.parseInt(data[1]);
				for (int i=0; i < N; i++) {
					int xl = Integer.parseInt(data[2 + 4*i]);
					int yt = Integer.parseInt(data[3 + 4*i]);
					int xr = Integer.parseInt(data[4 + 4*i]);
					int yb = Integer.parseInt(data[5 + 4*i]);
	
					modelRect.add(new Rectangle(imageName, xl, yt, xr, yb));
				}
			}
		}
		catch (Exception e) {
			System.err.println("ERROR: unable to parse ground truth data.");
			e.printStackTrace();
			System.exit(0);
		}
		
		for (int i=0; i < was.length; i++)
			if (!was[i]) {
				System.err.println("WARNING: no entry for " + imageNames.get(i) + " in the ground truth data.");
			}
		
		printMessage(modelRect.size() + " craters found in the ground truth data.");
		
		printMessage("Parsing return from your solution.");
		
		List<Rectangle> userRect = new ArrayList<Rectangle>();

		if (craters.length > 100000) {
			System.err.println("ERROR: Your solution returned more than 100000 craters.");
			System.exit(0);
		}

		for (String elm : craters) {
			String[] items = elm.split(" ");

			if (items.length != 5 || elm.endsWith(" ")) {
				System.err.println("ERROR: Your solution returned crater in improper format: \"" + elm + "\".");
				System.exit(0);
			}

			String imageName = items[0];

			boolean find = false;
			int W = -1, H = -1;
			for (int i = 0; i < imageNames.size(); i++)
				if (imageNames.get(i).equals(imageName)) {
					find = true;
					W = imageW.get(i);
					H = imageH.get(i);
					break;
				}

			if (!find) {
				System.err.println("ERROR: Your solution returned crater in non-existing image: \"" + elm + "\".");
				System.exit(0);
			}

			int xl = parse(items[1], 0, W - 1);
			if (xl == -1) {
				System.err.println("ERROR: xl must be an integer between " + 0 + " and " + (W - 1) + ", with no insignificant leading zeros: \"" + elm + "\".");
				System.exit(0);
			}

			int yt = parse(items[2], 0, H - 1);
			if (yt == -1) {
				System.err.println("ERROR: yt must be an integer between " + 0 + " and " + (H - 1) + ", with no insignificant leading zeros: \"" + elm + "\".");
				System.exit(0);
			}

			int xr = parse(items[3], 0, W - 1);
			if (xr == -1) {
				System.err.println("ERROR: xr must be an integer between " + 0 + " and " + (W - 1) + ", with no insignificant leading zeros: \"" + elm + "\".");
				System.exit(0);
			}

			int yb = parse(items[4], 0, H - 1);
			if (yb == -1) {
				System.err.println("yb must be an integer between " + 0 + " and " + (H - 1) + ", with no insignificant leading zeros: \"" + elm + "\".");
				System.exit(0);
			}

			if (xl > xr) {
				System.err.println("xl must be less than or equal to xr: \"" + elm + "\".");
				System.exit(0);
			}

			if (yt > yb) {
				System.err.println("yt must be less than or equal to yb: \"" + elm + "\".");
				System.exit(0);
			}

			userRect.add(new Rectangle(imageName, xl, yt, xr, yb));
		}
		
		printMessage("Calculating score.");
		
		double score = 0.0;

		int A = modelRect.size();
		int B = userRect.size();

		boolean[] matched = new boolean[A];

		int detected = 0;

		for (int i=0; i < B; i++)
			for (int j=0; j < A; j++)
				if (!matched[j] && modelRect.get(j).imageName.equals(userRect.get(i).imageName) && overlap(modelRect.get(j), userRect.get(i))) {
					matched[j] = true;
					detected++;
					score += detected / (double)(i + 1);
					break;
				}

		score *= 1000000.0 / A;
		
		System.out.println("Score = " + score);
		
		System.exit(0);
	}
	
	static String solutionCmd = null;
	static String pathToImagesFile = "images.lst";
	static String pathToGTFile = "GTF.lst";
	static boolean debugInfo = true;
	
	public static void main(String[] args) throws Exception {
		for (int i = 0; i < args.length; i++) {
			if (args[i].equals("-exec")) {
				solutionCmd = args[++i];
			} else if (args[i].equals("-img")) {
				pathToImagesFile = args[++i];
			} else if (args[i].equals("-gtf")) {
				pathToGTFile = args[++i];
			} else if (args[i].equals("-silent")) {
				debugInfo = false;
			} else {
				System.out.println("WARNING: unknown argument " + args[i]);
			}
		}
		
		if (solutionCmd == null) {
			System.err.println("ERROR: please specify the command to execute your solution " +
					"using -exec \"command\"");
			System.exit(0);
		}
		
		new CraterDetectionTester();
	}
	
	class ErrorStreamRedirector extends Thread {
	    BufferedReader reader;
	    
	    public ErrorStreamRedirector(InputStream is) {
	        reader = new BufferedReader(new InputStreamReader(is));
	    }
	    
	    public void run() {
	        while (true) {
	        	String s = null;
	        	try {
					s = reader.readLine();
				} catch (Exception e) {
					e.printStackTrace();
					return;
				}
				if (s == null) {
					break;
				}
				System.err.println(s);
	        }
	    }
	}
}
