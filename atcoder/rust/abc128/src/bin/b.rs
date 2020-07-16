use proconio::*;

fn main() {
    input! {
        n: usize
    };
    let mut shop = Vec::new();
    for i in 0..n {
        input! {
            s: String,
            p: u32
        };
        shop.push((s, p, i + 1));
    }
    shop.sort_by(|a, b| a.0.cmp(&b.0).then(b.1.cmp(&a.1)));
    for i in 0..n {
        println!("{}", shop[i].2);
    }
}
