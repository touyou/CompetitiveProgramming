#![allow(unused_macros, unused_imports, dead_code)]
use std::io;

fn read_line() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s
}

macro_rules! from_line {
    ($($a:ident : $t:ty), +) => {
        $(let $a: $t;)+
        {
            let _line = read_line();
            let mut _it = _line.trim().split_whitespace();
            $($a = _it.next().unwrap().parse().unwrap();)+
            assert!(_it.next().is_none());
        }
    };
}

fn main() {
    from_line!(a1: u32, b1: u32);
    let fa = a1 as f64;
    let fb = b1 as f64;
    println!("{} {} {:.5}", a1/b1, a1%b1, fa/fb);
}
