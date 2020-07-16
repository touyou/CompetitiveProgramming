use proconio::*;

fn main() {
    input! {
        a: u32,
        b: u32
    };
    if a >= 13 {
        println!("{}", b);
    } else if a >= 6 {
        println!("{}", b / 2);
    } else {
        println!("0");
    }
}
