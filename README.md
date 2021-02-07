# LifeStream
uOttaHack4 Healthcare Project

## Inspiration

The COVID-19 pandemic has significantly impacted our healthcare system, resulting in a higher number of hospitalized patients. As a result hospitals have been running at or above capacity. We wanted to use technology to enable data driven decision making for hospital administrators to manage patients. 

## What it does

LifeStream is an ADT healthcare data streaming application that allows for real-time communication between hospitals across Canada through event-driven architecture. 

Users are able to monitor data from other hospitals and distribute patients in real-time, facilitating effective communication between healthcare institutions.

## How we built it

LifeStream's front end was created entirely in Figma by passionate UX designers.

LifeStream's backend was architected in Solace PubSub+ Cloud. Data processing components are hosted in a Google Cloud Platform Kubernetes Engine, and Managed Compute Instance and sent to Solace via HTTP Request. LifeStream's Pulse & ECG Data was streamed from Apple Watch to an Arduino based ESP32 Microcontroller which sends data to Solace via MQTTS. 

## Challenges we ran into

Creating backend servers that communicate with each other through a single VPC network for the MLLP adapter was a challenge to configure. Running MQTT messages to Solace was difficult as there are significant processing limitations. Bug smashing to get Solace connected working on MQTT was huge issue as there is no documentation on how to use SSL with Arduino based devices.

## Accomplishments that we're proud of

We are most proud of finishing the project within the time allocated, as we were unsure at the beginning if it was going to be possible. We are also proud of integrating the Apple Watch features into our design, as we (Austin, Belinda, Sharon) are unfamiliar with the Apple design system. Finally, the UX designers were used to designing for a mobile application. We challenged ourselves to go beyond mobile and tackle a desktop design, which we are quite proud of as we left our comfort zone a bit.


## What we learned

Austin, Belinda, and Sharon experienced their first Hackathon together, which was an amazing experience due to how much we connected over the project. It was an initial challenge, as we were initially lost at the beginning and did not know where to begin. Drawing from what we learned in class was helpful, as we were able to synthesize theory and design thinking, and apply it, despite our limited experience as UX designers. 

## What's next for LifeStream

LifeStream is going to be developed further into a full fledged enterprise tool and pitched to Trillium Health Partners.
