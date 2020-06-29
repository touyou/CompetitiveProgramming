use proconio::*;

fn main() {
    input! {
        n: i32,
        m: i32
    };
    let minute = (m as f32) * 6.0;
    let hour = ((n % 12) as f32) * 30.0 + 0.5 * (m as f32);
    let result = (minute - hour).abs();
    println!("{}", if result >= 180.0 { 360.0 - result } else { result });
}
