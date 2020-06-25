use proconio::*;

fn main() {
    input! {
        n: u32
    };
    println!("{}", (0..n).map(|_| {
        input! {
            a: u32
        };
        a.trailing_zeros()
    }).min().unwrap());
}
