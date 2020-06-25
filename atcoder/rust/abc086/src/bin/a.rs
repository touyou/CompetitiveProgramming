use proconio::*;

fn main() {
    input! {
        a: u32,
        b: u32
    };
    let ans = if (a * b) % 2 == 0 { "Even" } else { "Odd" };
    println!("{}", ans);
}
