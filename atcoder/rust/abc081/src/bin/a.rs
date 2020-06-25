use proconio::*;

fn main() {
    input! {
        s: String
    };
    println!("{}", s.chars().filter(|&c| c == '1').count());
}
