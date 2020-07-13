use proconio::*;

fn main() {
    input! {
        _n: u32,
        k: usize,
        s: String
    };
    let mut ans = String::new();
    for (index, c) in s.chars().enumerate() {
        if index == k - 1 {
            ans.push_str(&c.to_ascii_lowercase().to_string());
        } else {
            ans.push_str(&c.to_string());
        }
    }
    println!("{}", ans);
}
