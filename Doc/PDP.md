# Personal Development Plan (PDP)

**Name:** Joel Malagarriga Duarte  
**Track:** PRJ4 - Embedded Systems  
**Project:** Smart Radiator Thermostat  
**Start Date:** 24.02.2025[^1]

This Personal Development Plan outlines my goals and progress during the semester. It is based on the HBO-i framework, and structured week-by-week to reflect on both technical and professional development.

---

## Learning Goals

Defined using the HBO-i framework. See full LO descriptions and interpretations: [Learning Goals →](./HBO-i.md)

| LO # | Summary |
|------|---------|
| 1    | Execute project in agile way within Embedded Systems context |
| 2    | Apply professional skills: leadership, communication, investigation |

---

## Weekly Log

For an overview of the original weekly planning, see:  
[Weekly Plan Overview →](../Files/WeeklyPlan.pdf)

---

### Week 1 | 24.02

**Plan:**  
- `LO1` Join a project group  
- `LO1` Brainstorm and for a project idea   
- `LO2` Discuss brainstormed project ideas and exchange reasoning 

**Reflection:**  
We found a project idea quite quickly, which helped set a clear direction early on. Since we are a group of two, there is no formal leadership structure, but we have a very close 1-on-1 dynamic that allows for direct, continuous communication and decision-making. This made collaboration efficient and transparent.

**Evidence:**  
- [Smart Radiator Thermostat Project Outlines →](../Files/Smart_Radiator_Thermostat_Project.pdf)  
- [List of Ideas →](../Files/Ideas.txt)  


---

### Week 2 | 10.03

**Plan:**  
- `LO1` I will follow the INES/OSCO course lessons to improve my proficiency in C, which is essential for programming embedded systems and writing firmware for our project.  
- `LO1` I will complete the assigned C programming exercises to get experience with key concepts like pointers, threads, and semaphores.  
- `LO2` I will collaborate with my OSCO course partner by reviewing each other's code, exchanging feedback, and reflecting on that feedback to improve my coding practices and communication.

**Reflection:**  
This week focused on improving my programming skills in C, which I’ll need for our embedded system. Some concepts were challenging at first, but going over the assignments in the feedback talk helped. Sitting down with my OSCO course partner to review code and exchange feedback was very valuable. It forced to being able to explain my choices more clearly and helped me identify areas for improvement I hadn’t noticed. Reflecting on the feedback made the learning process more intentional.

**Evidence:**  
- [C Assignment Solutions →](../Files/C_Assignments/)    
- [C Assignments Feedback + Reflection →](../Files/C_Assignments_Feedback_reflection.txt)


---

### Week 3 | 17.03

**Plan:**  
- `LO1` I will complete the embedded assignments to get a better understanding of hardware behavior and embedded programming.    
- `LO1` I plan to start exploring viable 3D printing materials for our project casing, based on strength, insulation, and accessibility.  
- `LO2` I will collaborate with my teammate during breadboard wiring and testing sessions, using clear division of tasks. I also intend to document and explain the wiring to reinforce shared understanding.

**Reflection:**  
Completing the embedded tasks helped solidify core knowledge, especially around PWM and I2C — both essential for controlling peripherals. I also improved my ability with breadboard wiring and testing. While I intended to research materials and the ESP8266 in detail, I only gathered some surface-level insights. However, this created a good base to build on in future weeks. Working with my teammate was effective again. We alternated tasks and made sure we both understood what was wired and why.

**Evidence:**  
- [INES Assignment Submission →](../Files/INES_Assingments/)  
- [Breadboard Setup →](../Files/I2C_Breadboard.png)  
- [Initial Material Notes →](../Files/material_notes.md)  
- [Wiring Explanation Notes →](../Files/circuit.png)


---


### Week 4 | 24.03

**Plan:**  
- `LO1` Finalize a list of key hardware components to allow early prototyping and ordering  
- `LO1` Research motor types relevant for precise thermal valve actuation  
- `LO1` Sketch a preliminary system layout to better understand integration challenges  
- `LO2` Discuss mechanical concepts and expectations with teammate to ensure shared understanding and avoid misalignment  

**Reflection:**  
This week we moved from learning concepts to more concrete planning. While initially focused on choosing components, we realized that did not think about power management but once we looked at the motor-driver combination we fixed that. Researching motor types was helpful to understand trade-offs, and we chose a stepper motor for its precision. The early system sketch also helped visualize integration challenges and plan for enclosure design. Collaboration with my teammate ensured we shared a clear vision of how the mechanism should behave.

**Evidence:**  
- [Motor Comparison Notes →](../Files/Motor_Comparison.md)  
- [Power Budget Calculation →](../Files/Power_Estimates.xlsx)  
- [System Diagram Sketch →](../Files/Idea_Sketch.pdf)  
- [Mechanism Demo Video →](../Files/MechanismVideo.mp4) 
- [Compontent List #Missing →](../Files/Component_List_Group03.xlsx) 


---


### Week 5 | 31.03

**Plan:**  
- `LO1` Focus on INES lessons to improve foundational knowledge for upcoming project implementation  
- *(No planned LO2 activities this week due to project pacing and workload balance)*

**Reflection:**  
This week was intentionally lighter to prepare for the upcoming Project Weeks and catch up with other Subjects. I used the time to focus on the INES course content, particularly on analog input and signal processing. This is directly relevant for reading sensor values (e.g. temperature) in our thermostat. While no additional LO2 skills were actively practiced, the learning in INES will support future technical decision-making.

**Evidence:**  
- [INES Analog Input/Reading Assignment →](../Files/INES_Assingments/)  


---


### Project Weeks | PW1 (08.04) & PW2 (15.04)

**Plan (PW1):**  
- `LO1` Connect and test motor driver, stepper motor, and AC power supply  
- `LO1` Begin LoRa communication setup between devices  
- `LO1` 3D print initial mechanical components for housing and actuator  
- `LO2` Define sprint goals for the next phase of development  
- `LO2` Set up a lightweight scrum routine with sprint planning and check-ins  
*Note: Any remaining or blocked tasks from PW1 will be addressed and finalized in PW2.*

**Reflection (PW2):**  
During PW1, we successfully powered the motor and driver and began writing code for controlling the actuator. The LoRa modules were set up. We 3D printed some basic parts and got an introduction into using 3D printers and how do combine them with embedded systems. We also established a basic sprint goal board and held our first planning session, which helped improve focus and communication in our small team.

**Evidence:**  
- [Motor Test Code →](../Files/Testing_for_Prj4/src/main.cpp)  
- [3D Printed Parts v1 →](../Files/3D_Parts/)  
- [Sprint Goals & Scrum Notes →](../Files/sprintMeeting.md)  
- [LoRa Initial Code →](../Files/LoRa.txt)


---


### Week 8 | 21.04

**Plan:**  
- `LO1` Review the previous sprint’s progress and address any unfinished tasks or issues.   
- `LO2` Collaborate with my project partner to ensure shared understanding of progress.

**Reflection:**  
This week was dedicated to review the work from the last sprint. We identified some hardware connection issues that needed attention, which we fixed together. Taking time to clean up improved overall system stability and helped us prepare for upcoming features. Communication with my partner remained clear and efficient, which contributed to resolving issues quickly.

**Evidence:**  
- [Sprint Review Notes →](../Files/Sprint_Review.md) 


---

### Week 9 | 05.05

**Plan:**  
- `LO1` Improve LoRa communication capabilities.  
- `LO1` Enhance user feedback through screen interfaces.  

**Reflection:**  
This week was dedicated to improving wireless communication and user interface. The enhancements to LoRa communication allow more reliable remote data transmission. Implementing screen feedback improved usability by giving clear system status.  

**Evidence:**  
- [LoRa Communication Logs →](../Files/LoRa_Communication_Week9.md)  # add
- [Screen Feedback Implementation →](../Files/Screen_Feedback_Code.md)  # add


---


### Week 10 | 12.05

**Plan:**  
- `LO1` Design and iterate on 3D printable parts to house the stepper motor securely.  
- `LO1` Print and test prototype cases, making adjustments as needed.  
- `LO2` Discuss design improvements and assembly procedures with partner to ensure fit and function.  

**Reflection:**  
The 3D printing week was valuable for developing mechanical design skills and prototyping. Iterative printing led to a secure and functional motor housing. Close communication with my partner ensured the design met assembly needs and project goals.  

**Evidence:**  
- [3D Design Files →](../Files/Motor_Case_Design.stl) # add
- [Photos of Printed Prototypes →](../Files/Printed_Prototypes_Week10.jpg) # add


---


### Week 11 | 19.05

**Plan:**  
- `LO1` Conduct a hardware review to check if initial ideas still allign with current vision 
- `LO1` Update parts that dont allign with our current ideas
- `LO2` Reflect on the decision-making process and collaborate with my group member 

**Reflection:**  
After reviewing our current hardware the temperatur sensor, the Honeywell HIH-4030, was identified as a not usable for our project. Researching alternatives helped deepen my understanding of sensor specifications and project requirements. The waterproof DS18B20 was selected for its balance of precision and environmental protection, which fits our needs better than the non-waterproof version. Group discussions were valuable in ensuring shared understanding and planning next steps.For future hardware lists the project envirement and the technological size should be tought about.

**Evidence:**  
- [Sensor Comparison Document →](../Files/Sensor_Comparison.md)[^2]  


---


### Project Weeks | PW3 (26.05) & PW4 (02.06) & PW5 (09.06)

**Plan (PW3):**  
- `LO1` 3D print final version of the motor casing.  
- `LO1` Develop code for the wireless remote and its display.  
- `LO1` Improve and finalize LoRa communication code.  
- `LO1` Integrate temperature sensor and implement calculation logic.  
- `LO1` Write motor control logic including movement and stop function.  
- `LO1` Create calibration code (if time allows).  
- `LO1` Design casing for the remote control (optional, if time permits).  
- `LO1` Assemble and test full system in a realistic setup. 
- `LO2` Conduct sprint planning to distribute tasks, set technical priorities, and structure workload across team.   

*Note: Any remaining or blocked tasks from PW3 will be addressed and finalized in PW4 & PW5.*

**Reflection (PW5):**  

**Evidence:**  
- [Sprint Planning Notes →](../Files/SprintPlaning.md) 
- [3D Modeling Process – Jupyter Notebook →](../Files/3D_modeling.ipynb) # update

---
[^1]: Week 1 start at the 24th of February, since due to complications that is when my group was formed.
[^2]: Ask if i need to add sources to the evidence, such as links for my comparison
