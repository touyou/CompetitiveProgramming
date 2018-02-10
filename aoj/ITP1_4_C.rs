
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
    loop {
        from_line!(a: i32, op: String, b: i32);
        if op == "?" {
            break;
        }
        let ret = match &*op {
            "+" => a + b,
            "-" => a - b,
            "*" => a * b,
            "/" => a / b,
            _ => 0,
        };
        println!("{}", ret);
    }
}
