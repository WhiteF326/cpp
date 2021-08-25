import std.stdio;
import std.string;
import std.conv;

void main(){
  int n = readln.chomp.to!int;
  if (n % 4 == 0) {
    writefln("Yes");
  } else {
    writefln("No");
  }
}
