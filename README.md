## Introduction
This work is a proof of concept of a minimal version of SOFA Framework.

SofaMinimal contains:
- SofaMinimal0 = SofaCore + SofaHelper + SofaDefaultType + SofaSimulationCommon
- SofaMinimal1 = SofaMinimal0 + Most basic components of SOFA
- SofaMinimal2 = SofaMinimal1 + classic/often-used components of SOFA
- SofaMinimal3 = SofaMinimal2 + components present in SOFA scene tests

## List of components / Roadmap (Kind of)
https://goo.gl/XoYa9L

## BUGFIXES/TODOS:
 - [MechanicalObject] remove regulargrid deps 
 - [MechanicalObject] remove/move laparoscopicrigid
 - [FixedConstraint] remove deps on topology ?
 - [Engines] template names
 - [DiscreteIntersection] remove ugly dependencies

## TASKS:
 - ~~[Architecture] see how to remove topologies from mechanicalobject~~
 - [Architecture] see how to remove explicit deps of Point/Triangle/etc from topologyengine (by extension remove these deps for MechanicalObject)
 - [Architecture] think about topology change architecture (new classes ? decorator...)
 - [Tests] A lots of tests depends on SceneCreator (which depends on almost everything)