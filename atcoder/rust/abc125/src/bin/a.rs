use proconio::*;

fn main() {
    input! {
        a: i32,
        b: i32,
        t: i32
    };
    println!("{}", (t / a) * b);
}
