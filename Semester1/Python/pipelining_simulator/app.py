# app.py
import streamlit as st
from pipeline_core import count_stalls

st.set_page_config(page_title="Pipeline Simulator", page_icon="🧠", layout="centered")

st.title("🧠 Pipeline Simulation")
st.markdown("Simulate **Load-Use Hazards** and count total stalls interactively.")

# Input box
user_input = st.text_area(
    "Enter your instructions (end with END):",
    placeholder="Example:\n"
                "lw $t0 , 0\n"
                "add $t2 , $t0 , $t3\n"
                "lw $t4 , 1\n"
                "sw $t4 , 2\n"
                "sub $t5 , $t0 , $t2\n"
                "END",
    height=220
)

# Button
if st.button("▶️ Run Simulation"):
    lines = [line.strip() for line in user_input.strip().split("\n") if line.strip()]
    if "END" in lines:
        lines = lines[:lines.index("END")]

    if lines:
        stalls = count_stalls(lines)
        st.success(f"✅ Total Stalls : {stalls}")
    else:
        st.warning("Please enter valid instructions before END.")

st.markdown("---")
st.caption("Developed by Mithun,Arshad,Mariya")