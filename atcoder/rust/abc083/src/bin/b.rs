use proconio::*;

fn main() {
    input! {
        n: u32,
        a: u32,
        b: u32
    }
    let ans = (1..n+1).filter(|x| {
        let sum = x.to_string().chars().map(|c| (c as u8 - b'0') as u32).sum::<u32>();
        a <= sum && sum <= b
    }).sum::<u32>();
    println!("{}", ans);
}
