use proconio::*;

fn main() {
    input! {
        r: u32,
        d: u32,
        mut x: u32
    };
    for _ in 0..10 {
        x = r * x - d;
        println!("{}", x);
    }
}
