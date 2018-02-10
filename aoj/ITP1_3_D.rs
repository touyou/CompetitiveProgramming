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
    from_line!(a: u32, b: u32, c: u32);
    let mut cnt = 0;
    for i in a..(b+1) {
        if c % i == 0 {
            cnt += 1;
        }
    }
    println!("{}", cnt);
}
