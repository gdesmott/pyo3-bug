use pyo3::prelude::*;

fn main () {
    let gil = Python::acquire_gil();
    let py = gil.python();

    PyModule::from_code(
        py,
        "
import tensorflow
",
        "test.py",
        "test",
    )
    .map_err(|e| {
        e.print_and_set_sys_last_vars(py);
    }).unwrap();
}
