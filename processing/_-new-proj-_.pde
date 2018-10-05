PImage img_orig, img;
float s;
int window_size;
int mode;
int x1, y1, x2, y2;

void setup() {
	size(640, 480);
	noSmooth();
	//noLoop();
	img_orig = loadImage("e:/_tot/_3_PROJECTS/images/dots.png");
	img = createImage(img_orig.width, img_orig.height, ARGB);

	s = 4;
	window_size = 3;
	mode = 11;
	process();
}

void mouseWheel(MouseEvent event) {
  float e = event.getCount();
  window_size += e/abs(e);
  window_size = max(1, window_size);
  println(window_size);
	process();
}

void keyPressed() {
	if (key == 'q') exit();
	if (key == 'p') process();
	if (key == '-') { s /= 2; println("s:", s); }
	if (key == '+') { s *= 2; println("s:", s); }
	if (key == ',') { window_size--; println("window_size:", window_size); }
	if (key == '.') { window_size++; println("window_size:", window_size); }
	if (key == '[') { mode--; println("mode:", mode); }
	if (key == ']') { mode++; println("mode:", mode); }
}

void mouseReleased() {
  if (mouseButton == LEFT) {
    x1 = mouseX;
    y1 = mouseY;
  }
  if (mouseButton == RIGHT) {
    x2 = mouseX;
    y2 = mouseY;
  }
  if (mouseButton == CENTER) {
    color c = get(mouseX, mouseY);
    println(red(c), green(c), blue(c)); 
  }
}

void draw() {
	image(img_orig, 0, 0, img_orig.width*s, img_orig.height*s);
	image(img, 0, 0, img.width*s, img.height*s);
	if (mousePressed) { rect(0, 0, mouseX, mouseY); }
}

void process() {
	img_orig.loadPixels(); img.loadPixels();

	img_orig.updatePixels(); img.updatePixels();
	println("processed");
}
