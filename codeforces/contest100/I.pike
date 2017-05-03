#! /usr/bin/env pike

int main() {
	float k, x, y;
	string kin, xyin;
	kin = Stdio.stdin.gets();
	xyin = Stdio.stdin.gets();
	sscanf(kin,"%f",k);
	sscanf(xyin, "%f%f", x, y);
	
	float resx, resy;
	resx = x + cos(-k/180)*x;
	resy = y + sin(-k/180)*y;
	write("%.8f %.8f\n",resx,resy);
}
